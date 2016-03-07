/*
 * register.h
 *
 *  Created on: 2 mars 2016
 *      Author: joel
 */

#include <systemc.h>

SC_MODULE ( module_register) {
	sc_in < bool > clk;
	sc_in < sc_logic > din;
	sc_out < sc_logic > dout;

	void methode_register (){
			dout.write(din.read());
	}

	SC_CTOR ( module_register ) {

		SC_METHOD (methode_register);
		dout.initialize(SC_LOGIC_0); // inicializar el puerto de salida "dout" SC_LOGIC_0 , SC_LOGIC_1  , SC_LOGIC_X , SC_LOGIC_Z    X= peut import le valeur , Z= alta impedancia
		sensitive << clk.pos();
		dont_initialize(); // no inicializar el proceso "methode_register"

	}

};
