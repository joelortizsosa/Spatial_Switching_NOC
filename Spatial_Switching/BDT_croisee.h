/*
 * BDT_croisee.h
 *
 *  Created on: 3 mars 2016
 *      Author: joel
 */

#include <systemc>
#include "xor2.h"
#include "nand3.h"
#include "register.h"

SC_MODULE (module_Bdt_croisee) {
	// Declaration des ports
		sc_in   <   bool   > clk;
		sc_in   < sc_logic > fil_j, fil_j1;
		sc_in   < sc_logic > fil_j_code, fil_j1_code;
		sc_out  < sc_logic > S_switch;
	// Appel de module NAND et XOR
		module_nand NAND;
		module_xor XOR0, XOR1, XOR2;
		module_register R0, R1;
		sc_signal <sc_logic> S1, S2, S3, S4, S5;
	SC_CTOR (module_Bdt_croisee) : NAND("NAND"), XOR0("XOR0"), XOR1("XOR1"), XOR2("XOR2"), R0("R0"), R1("R1"){

		NAND (S3, S4, S5, S_switch);
		XOR0 (S1, fil_j, S3);
		XOR1 (S2, fil_j1, S4 );
		XOR2 (fil_j, fil_j1, S5);
		R0    (clk, fil_j_code, S1);
		R1    (clk, fil_j1_code, S2);

	}


};
