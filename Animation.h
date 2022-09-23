#pragma once
class Animation
{
public:
	short Animate();
	void Start();

private:
	short Progression = 10;

	bool Half_done = false;
	bool End = false;
};

