# Air Conditioning Sensor

A remote sensor for [Air Conditioning Controller](https://github.com/pamelus/air-conditioning-controller) providing
information about temperature or temperature & humidity. Measures in intervals, then sends measures via Serial (over
HC-12 433 Mhz radio bridge) to the controlling unit, and then goes to sleep. Average power consumption on Arduino Pro
Mini 8Mhz 3.3V (power led soldered out) the power led, is around 0.02mA.