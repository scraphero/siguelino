// PINS   | PINS
	const int left_backward = 9 ;
	const int left_forward = 3 ;
	const int right_backward = 5 ;
	const int right_forward = 10 ;

// SETUP  | ARDUINO SETUP
	void setup()
	{
		pinMode(right_backward , OUTPUT );
		pinMode(right_forward , OUTPUT );
		pinMode(left_backward , OUTPUT );
		pinMode(left_forward , OUTPUT );
	}

// LOOP   | ARDUINO LOOP
	void loop()
	{
		// LEFT Wheel
			analogWrite ( right_backward, 0 );
		  analogWrite ( right_forward,  0 );
		// RIGHT Wheel
	  	analogWrite ( left_backward, 0 );
	  	analogWrite ( left_forward,  0 );

	delay(1000);

		// LEFT Wheel
			analogWrite ( right_backward, 0 );
		  analogWrite ( right_forward,  150 );
		// RIGHT Wheel
	  	analogWrite ( left_backward, 0 );
	  	analogWrite ( left_forward,  150);

	  delay(100);
	  // LEFT Wheel
			analogWrite ( right_backward, 0 );
		  analogWrite ( right_forward,  150 );
		// RIGHT Wheel
	  	analogWrite ( left_backward, 0 );
	  	analogWrite ( left_forward,  0 );

	  delay(500);
	}
