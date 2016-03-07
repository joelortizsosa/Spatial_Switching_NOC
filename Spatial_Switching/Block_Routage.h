/*
 * Block_Routage.h
 *
 *  Created on: 4 mars 2016
 *      Author: joel
 */

#include <systemc.h>
#include "mux.h"
SC_MODULE ( module_Block_Routage )
{
// Declaration des ports
	sc_in < sc_logic> fil_j, fil_j1, S_switch;
	sc_out <sc_logic> fil_j_out, fil_j1_out;
// Appel de module MUX
	module_mux MUX0, MUX1;


	SC_CTOR( module_Block_Routage ): MUX0("MUX0"), MUX1("MUX1"){

		MUX0 (fil_j1, fil_j, S_switch, fil_j_out);
		MUX1 (fil_j, fil_j1, S_switch, fil_j1_out);
		//sensitive<<S_switch<<a_in<<b_in;
	}
};
