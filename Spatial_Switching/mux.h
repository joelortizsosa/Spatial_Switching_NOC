/*
 * mux.h
 *
 *  Created on: 1 mars 2016
 *      Author: joel
 */


#include <systemc.h>

SC_MODULE ( module_mux )
{

sc_in	<sc_logic >  a_in, b_in;
sc_in	<sc_logic >  S_switch;
sc_out<sc_logic > out_sig;

void methode_mux(){
	if ( S_switch == '0') {
		out_sig= a_in;
	}else {
		out_sig= b_in;
	}

}
	SC_CTOR ( module_mux ){
		SC_METHOD( methode_mux );
		sensitive<<S_switch<<a_in<<b_in;
	}

};
