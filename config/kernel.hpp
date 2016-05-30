using Nugraha::Contracts::Devices::DriverContract;
using Nugraha::Devices::Device;

DriverContract* Device::defaultDriver = new Drivers::SinkModeDriver();
