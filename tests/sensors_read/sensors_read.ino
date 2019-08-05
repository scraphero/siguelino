// PINS
	int D1 = A0 ;  // Extreme right
	int D2 = A1 ;  // etc.
	int D3 = A2 ;  // etc.
	int D4 = A3 ;  // Center right
	int D5 = A4 ;  // Center Left
	int D6 = A5 ;  // etc.
	int D7 = A6 ;  // etc.
	int D8 = A7 ;  // Extreme Left

// SETUP
	void setup()
	{
		Serial.begin(9600);
	}

// LOOP
	void loop()
	{
		Serial.print(analogRead(D1));
		Serial.print(" ");
		Serial.print(analogRead(D2));
		Serial.print(" ");
		Serial.print(analogRead(D3));
		Serial.print(" ");
		Serial.print(analogRead(D4));
		Serial.print(" ");
		Serial.print(analogRead(D5));
		Serial.print(" ");
		Serial.print(analogRead(D6));
		Serial.print(" ");
		Serial.print(analogRead(D7));
		Serial.print(" ");
		Serial.println(analogRead(D8));
	}
