#ifndef STATE_H
#define STATE_H

class State
{
public:
	virtual void init() = 0;

	virtual void processEvents() = 0;
	virtual void update(float dt) = 0;
	virtual void draw(float dt) = 0;

	virtual void pause() {}
	virtual void resume() {}
private:

};

#endif