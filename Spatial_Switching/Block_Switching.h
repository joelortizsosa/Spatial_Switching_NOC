/*
 * Block_Switching.h
 *
 *  Created on: 4 mars 2016
 *      Author: joel
 */
#include <systemc>
#include "BDT_croisee.h"
#include "Block_Routage.h"

SC_MODULE (module_Block_Switching){

// ::::::::::::::: Declaration de ports:::::::::::::::::/

	sc_in	 <	bool		>	clk;
	sc_in	 <	sc_logic	>	fil_j, fil_j1;
	sc_out	 <	sc_logic	>	S_switch, fil_j_code, fil_j1_code;

// ::::::::::::::: Appeler les modules :::::::::::::::::/

	module_Block_Routage Mod_BRoutage;
	module_Bdt_croisee Mod_BDTC;

// ::::::::: Declaration des signals de conection ::::::/

	//sc_signal<	sc_logic	> S1, S2, S3;

// ::::::::: Conections de cahque module :::::::::::::::/

	SC_CTOR (module_Block_Switching): Mod_BRoutage("Mod_BRoutage"), Mod_BDTC("Mod_BDTC"){



		Mod_BRoutage	(fil_j, fil_j1, S_switch, fil_j_code, fil_j1_code);

		Mod_BDTC		(clk, fil_j, fil_j1, fil_j_code, fil_j1_code, S_switch );



	}

};
