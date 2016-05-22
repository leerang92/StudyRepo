using UnityEngine;
using System.Collections;

public class MeteoCtrl : MonoBehaviour {

    public float speed = 3f;

	// Update is called once per frame
	void Update () {
        if (Timer.instance.bOver)
            return;

        transform.Translate(Vector3.down * speed * Time.deltaTime);

        Destroy(this.gameObject, 5f);
	}

}
