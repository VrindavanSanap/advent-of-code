'use strict';

function encode( w ) {
	var output = '';
	var current = undefined;
	var counter = 0;
	for ( var i = 0; i < w.length; i++ ) {
		if ( current ) {
			if ( current == w[i] ) {
		        counter = counter + 1;
		      } else {
		        output += counter + current;
		        current = w[i];
		        counter = 1;
		      }
		} else {
			current = w[i];
			counter = 1;
		}
	}
	return output + counter + current;
}

function calculate( s, times ) {
	var value = s;
	for ( var i = 0; i < times; i++ ) {
		var t0 = new Date()
		value = encode(value)
		var t1 = new Date()
		console.log( (i + 1) + ' - ' + value.length + ' - ' + ( t1.getTime() - t0.getTime() )/60)
	}
	return value.length
}

console.log( calculate( input, 40 ) );

