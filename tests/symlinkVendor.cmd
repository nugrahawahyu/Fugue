@echo off

set librariesDir="D:\\Code\\MicrocontrollerProjects\\libraries"
set vendorDir=PWD

mklink /J  "C:\\Users\\Nugraha\\OneDrive\\Tugas Akhir Deyen\\Code\\Fugue\\vendor\\libraries\\ArduinoJson" "D:\\Code\\MicrocontrollerProjects\\libraries\\ArduinoJson"
mklink /J  "C:\\Users\\Nugraha\\OneDrive\\Tugas Akhir Deyen\\Code\\Fugue\\vendor\\libraries\\DallasTemperature" "D:\\Code\\MicrocontrollerProjects\\libraries\\DallasTemperature"
mklink /J  "C:\\Users\\Nugraha\\OneDrive\\Tugas Akhir Deyen\\Code\\Fugue\\vendor\\libraries\\OneWire" "D:\\Code\\MicrocontrollerProjects\\libraries\\OneWire"

pause