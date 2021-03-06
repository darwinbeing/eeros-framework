#include <eeros/hal/FlinkFqd.hpp>

using namespace eeros::hal;

FlinkFqd::FlinkFqd(std::string id, 
					 FlinkDevice* device,
					 uint32_t subDeviceNumber,
					 uint32_t channel,
					 double scale,
					 double offset) : 
					 ScalablePeripheralInput<double>(id, scale, offset), channel(channel), prevPos(0) {
	this->subdeviceHandle = flink_get_subdevice_by_id(device->getDeviceHandle(), subDeviceNumber);
	reset();
}

double FlinkFqd::get() {
	uint32_t data = 0;
	flink_counter_get_count(subdeviceHandle, channel, &data);
	int16_t newPos = static_cast<uint16_t>(data);
	int16_t delta = newPos - prevPos;
	prevPos = newPos;
	pos += delta * scale + offset;
	return pos;
}

void FlinkFqd::reset() {
	flink_subdevice_reset(subdeviceHandle); // TODO only reset counter, not the subdevice!
	pos = 0;
}
