#ifndef ORG_EEROS_CONTROL_STEP_HPP_
#define ORG_EEROS_CONTROL_STEP_HPP_

#include <eeros/control/Block1o.hpp>
#include <eeros/core/System.hpp>

class Step: public Block1o
{
public:
	Step(double initValue = 0, double stepHeight = 1, double delayTime = 0);
	Step(sigdim_t dim, double initValue = 0, double stepHeight = 1, double delayTime = 0);
	Step(sigdim_t dim, double initValue[], double stepHeight[], double delayTime = 0);
	virtual ~Step();

	virtual void run();
	
	virtual void reset();
	virtual void setinitValue(double initValue);
	virtual void setinitValue(double initValue, int index);
	virtual void setStepHeight(double stepHeight);
	virtual void setStepHeight(double stepHeight, int index);
	virtual void setDelayTime(double delayTime);

private:
	double* initValue;
	double* stepHeight;
	double stepTime;
	bool stepDone;
	bool first;
};

#endif /* ORG_EEROS_CONTROL_STEP_HPP_ */