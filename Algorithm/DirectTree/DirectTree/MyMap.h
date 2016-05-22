#pragma once
class CMyMap
{
	int **m_map;
	int m_width;
	int m_height;
public:
	CMyMap();
	~CMyMap();
	CMyMap(int w, int h) : m_width(w), m_height(h) {
		m_map = new int *[h];
		for (int i = 0; i < h; i++)
			m_map[i] = new int[w];
	}
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	int **getMap() { return m_map; }
	void setMap(int **map);
	void draw();
};

