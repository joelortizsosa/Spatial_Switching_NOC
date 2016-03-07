/*
 * Bloc_Deswitching.h
 *
 *  Created on: 1 mars 2016
 *      Author: joel
 */


#include <systemc.h>
#include "Block_Routage.h"
SC_MODULE ( module_Block_Deswitching )
{
// Declaration des ports
	sc_in < sc_logic> fil_j, fil_j1, S_switch;
	sc_out <sc_logic> fil_j_out, fil_j1_out;
// Appel de module MUX
	module_Block_Routage BLOCKROUTAGE;


	SC_CTOR( module_Block_Deswitching ): BLOCKROUTAGE("BLOCKROUTAGE"){

		BLOCKROUTAGE (fil_j, fil_j1, S_switch, fil_j_out, fil_j1_out);

	}
};
