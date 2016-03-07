/*
 * xor2.h
 *
 *  Created on: 3 mars 2016
 *      Author: joel
 */

#include<systemc.h>

SC_MODULE(module_xor){
	sc_in<sc_logic> a, b;
	sc_out<sc_logic> axorb;

	void methode_xor() {
		axorb= sc_logic(a) ^ sc_logic(b);
	}

	SC_CTOR(module_xor){
		SC_METHOD(methode_xor);

		sensitive << a << b;
		dont_initialize();
	}
};
