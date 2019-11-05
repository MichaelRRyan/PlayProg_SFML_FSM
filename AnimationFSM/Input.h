#ifndef INPUT_H
#define INPUT_H
class Input
{
public:
	Input();
	~Input();

	void setAllFalse();

	bool m_up;
	bool m_down;
	bool m_left;
	bool m_leftPressed;
	bool m_right;
};
#endif