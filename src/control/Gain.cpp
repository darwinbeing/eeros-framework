#include <eeros/control/Gain.hpp>

Gain::Gain(double gain) : Block1i1o(1) {
	this->gain = new double[1];
	this->gain[0] = gain;
	this->enabled = true;
}

Gain::Gain(sigdim_t dim, double gain[]) : Block1i1o(dim) {
	if(sizeof(gain) / sizeof(gain[0]) == dim) { // TODO check what happens if lenght of array is 0!
		this->gain = new double[dim];
		for(int i = 0; i < dim; i++)
		{
			this->gain[i] = gain[i];
		}
		this->enabled = true;
	}
}

Gain::~Gain() {
// 	delete this->out;
// 	delete this->gain;
}

void Gain::run()
{
	for(int i = 0; i < out.getLength(); i++)
	{
		if(enabled) out.setValue(in.getValue(i) * gain[i], i);
		else out.setValue(in.getValue(i), i);
	}
}

void Gain::enable()
{
	this->enabled = true;
}

void Gain::disable()
{
	this->enabled = true;
}

void Gain::setGain(double gain)
{
	setGain(0);
}
	
void Gain::setGain(double gain, int index)
{
	this->gain[index] = gain;
}