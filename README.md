# Air Conditioning Sensor

A remote sensor for [Home Climate Controller](https://github.com/ptkoz/infodisplay-controller) providing
information about temperature or temperature & humidity. Measures in intervals, then sends measures via Serial (over
HC-12 433 Mhz radio bridge) to the controlling unit, and then goes to sleep. Average power consumption on Arduino Pro
Mini 8Mhz 3.3V (power led soldered out) is around 0.02mA.