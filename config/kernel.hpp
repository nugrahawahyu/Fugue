using Nugraha::Contracts::Drivers::Devices::DriverContract;
using Nugraha::Devices::Device;

DriverContract* Device::defaultDriver = new Drivers::SinkModeDriver();