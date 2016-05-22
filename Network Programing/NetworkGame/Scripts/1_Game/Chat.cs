using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Net;

public class Chat : MonoBehaviour
{
	public static Chat instance;
	public GameObject clientPlayer;
	public GameObject serverPlayer;
	private int serv = 0;
	private int cli = 0;
	private int exit = 0;
	void OnServerInitialized()
	{
		serv += 1;
		exit++;
		Network.Instantiate(serverPlayer, Vector3.up * 3.5f, Quaternion.identity, 0);
	}

	private void OnConnectedToServer()
	{
		cli += 1;
		exit++;
		Network.Instantiate(clientPlayer, Vector3.down * 3.5f, Quaternion.identity, 0);
	}



	void Awake()
	{
		instance = this;
		Debug.Log (22);
	}

	private TransportTCP	m_transport;
	
	
	private ChatState		m_state = ChatState.HOST_TYPE_SELECT;
	
	private	string 			m_hostAddress = "";
	
	private const int 		m_port = 50765;

	
	private string			m_sendComment = "";
	private string			m_prevComment = "";

	private string			m_chatMessage = "";

	private List<string>[]	m_message;

	private	bool			m_isServer = false;




	private static float	KADO_SIZE = 16.0f;
	private static float	FONT_SIZE   = 13.0f;
	private static float	FONG_HEIGHT = 18.0f;
	private static int		MESSAGE_LINE = 18;
	private static int		CHAT_MEMBER_NUM = 2;

	enum ChatState {
		HOST_TYPE_SELECT = 0,	// 방 선택.
		CHATTING,				// 채팅 중.
		LEAVE,					// 나가기.
		ERROR,					// 오류.
		START,
	};
	
	
	
	// Use this for initialization
	void Start()
	{
		IPHostEntry hostEntry = Dns.GetHostEntry(Dns.GetHostName());
		System.Net.IPAddress hostAddress = hostEntry.AddressList[0];
		Debug.Log(hostEntry.HostName);
		m_hostAddress = hostAddress.ToString ();

		GameObject go = new GameObject("Network");
		m_transport = go.AddComponent<TransportTCP>();

		m_transport.RegisterEventHandler(OnEventHandling);

		m_message = new List<string>[CHAT_MEMBER_NUM];
		for (int i = 0; i < CHAT_MEMBER_NUM; ++i) {
			m_message[i] = new List<string>();
		}
	}
	
	// Update is called once per frame
	void Update()
	{
		switch (m_state) {
		case ChatState.HOST_TYPE_SELECT:
			for (int i = 0; i < CHAT_MEMBER_NUM; ++i) {
				m_message[i].Clear();
			}
			break;

		case ChatState.CHATTING:
			UpdateChatting();
			break;
			
		case ChatState.LEAVE:
			UpdateLeave();
			break;
		case ChatState.START:
			UpdateLeave();
			break;
		}
	}
	
	void UpdateChatting()
	{
		byte[] buffer = new byte[1400];

		int recvSize = m_transport.Receive(ref buffer, buffer.Length);
		if (recvSize > 0) {
			string message = System.Text.Encoding.UTF8.GetString(buffer);
			Debug.Log("Recv data:" + message );
			m_chatMessage += message + "   ";// + "\n";

			int id = (m_isServer == true)? 1 : 0;
			AddMessage(ref m_message[id], message);
		}	
	}
	
	void UpdateLeave()
	{
		if (m_isServer == true) {
			m_transport.StopServer();
		}
		else {
			m_transport.Disconnect();
		}

		// 메시지 삭제.
		for (int i = 0; i < 2; ++i) {
			m_message[i].Clear();
		}
		
		m_state = ChatState.HOST_TYPE_SELECT;
	}
	
	void OnGUI()
	{
		switch (m_state) {
		case ChatState.HOST_TYPE_SELECT:
					
			SelectHostTypeGUI();
			break;
			
		case ChatState.CHATTING:

			ChattingGUI();
			break;

		case ChatState.ERROR:

			ErrorGUI();
			break;
		}
	}
	
	
	void SelectHostTypeGUI()
	{
        float sx = 200.0f;
        float sy = 200.0f;
        float px = sx * 0.5f - 100.0f;
        float py = sy * 0.75f;

        if (GUI.Button(new Rect(px, py, 200, 30), "채팅방 만들기")) {
			serv =+ 1;
			m_transport.StartServer(m_port, 1);

			m_state = ChatState.CHATTING;
			m_isServer = true;
		}


        Rect labelRect = new Rect(px, py + 80, 200, 30);
		GUIStyle style = new GUIStyle();
		style.fontStyle = FontStyle.Bold;
		style.normal.textColor = Color.white;
		GUI.Label(labelRect, "상대방 IP 주소", style);
		labelRect.y -= 2;
		style.fontStyle = FontStyle.Normal;
		style.normal.textColor = Color.black;
		GUI.Label(labelRect, "상대방 IP 주소", style);

		Rect textRect = new Rect(px, py + 100, 200, 30);
        m_hostAddress = GUI.TextField(textRect, m_hostAddress);


        if (GUI.Button(new Rect(px, py + 40, 200, 30), "채팅방 들어가기")) {
			cli =+ 1;
			bool ret = m_transport.Connect(m_hostAddress, m_port);
			if (ret) {
				m_state = ChatState.CHATTING;
			}
			else {
				m_state = ChatState.ERROR;
			}
		}
	}
	
	void ChattingGUI()
	{
		Rect commentRect = new Rect(10, 250, 100, 30);
		m_sendComment = GUI.TextField(commentRect, m_sendComment, 15);

		bool isSent = GUI.Button(new Rect (110, 250, 100, 30), "말하기");

		if (Event.current.isKey && 
		    Event.current.keyCode == KeyCode.Return) { 
			if (m_sendComment == m_prevComment) {
				isSent = true;
				m_prevComment = "";
			}
			else {
				m_prevComment = m_sendComment;
			}
		}
			
		if (isSent == true) {
			string message = "[" + DateTime.Now.ToString("HH:mm:ss") + "] " + m_sendComment;
			byte[] buffer = System.Text.Encoding.UTF8.GetBytes(message);		
			m_transport.Send(buffer, buffer.Length);
			AddMessage(ref m_message[(m_isServer == true)? 0 : 1], message);
			m_sendComment = "";
		}
		if (serv == 1) {
			if (GUI.Button (new Rect (110, 280, 100, 30), " 게임시작")) {
				//m_state = ChatState.LEAVE;
				Network.InitializeServer (2, m_port, false);
			}
		} 
		if(cli == 1) {
			if (GUI.Button (new Rect (110, 280, 100, 30), " 게임참가")) {
				Network.Connect (m_hostAddress, m_port);
			}
		}



		if (exit == 0) {
			if (GUI.Button (new Rect (120, 360, 80, 30), "나가기")) {
				m_state = ChatState.LEAVE;
			}
		}

		// 서버 메지 표시.
		if (m_transport.IsServer() ||
			m_transport.IsServer() == false && m_transport.IsConnected()) {
			DispBalloon(ref m_message[0], new Vector2(180.0f, 200.0f), new Vector2(340.0f, 360.0f), Color.cyan, true);

		}

		if (m_transport.IsServer() == false ||
			m_transport.IsServer() && m_transport.IsConnected()) {
			//클라이언트가 말하는 메시지 표시. 
			DispBalloon(ref m_message[1], new Vector2(300.0f, 200.0f), new Vector2(340.0f, 360.0f), Color.green, false);

		}
	}

	void ErrorGUI()
	{
		float sx = 800.0f;
		float sy = 600.0f;
		float px = sx * 0.5f - 150.0f;
		float py = sy * 0.5f;
		
		if (GUI.Button(new Rect(px, py, 300, 80), "접속에 실패했습니다.\n\n버튼을 누르세요.")) {
			m_state = ChatState.HOST_TYPE_SELECT;
		}	
	}

	void AddMessage(ref List<string> messages, string str)
	{
		while (messages.Count >= MESSAGE_LINE) {
			messages.RemoveAt(0);
		}

		messages.Add(str);
	}

	void DispBalloon(ref List<string> messages, Vector2 position, Vector2 size, Color color, bool left) 
	{

		// 채팅 문장을 표시합니다. 	
		foreach (string s in messages) {
			DrawText(s, position, size);
			position.y += FONG_HEIGHT;//글씨 쓰면 한칸 아래씩으로
		}
	}
				

	void DrawText(string message, Vector2 position, Vector2 size)
	{
		if(message == "") {
			return;
		}

		GUIStyle style = new GUIStyle();
		style.fontSize = 16;
		style.normal.textColor =  Color.white;

		Vector2		balloon_size, text_size;
		
		text_size.x = message.Length*FONT_SIZE;
		text_size.y = FONG_HEIGHT;
		
		balloon_size.x = text_size.x + KADO_SIZE*2.0f;
		balloon_size.y = text_size.y + KADO_SIZE;

		Vector2		p;
		
		p.x = position.x - size.x/2.0f + KADO_SIZE;
		p.y = position.y - size.y/2.0f + KADO_SIZE;

		GUI.Label(new Rect(p.x, p.y, text_size.x, text_size.y), message, style);
	}

	void OnApplicationQuit() {
		if (m_transport != null) {
			m_transport.StopServer();
		}
	}

	public void OnEventHandling(NetEventState state)
	{
		switch (state.type) {
		case NetEventType.Connect:
			if (m_transport.IsServer()) {
				AddMessage(ref m_message[1], "클라 입장");
			}
	
			break;

		case NetEventType.Disconnect:
			if (m_transport.IsServer()) {
				AddMessage(ref m_message[0], "클라 나갔다.");
			}
			else {
				AddMessage(ref m_message[1], "클라 나갔다.");
			}
			break;
		}
	}
}
