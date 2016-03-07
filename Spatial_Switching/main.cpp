/*
 * main.cpp
 *
 *  Created on: 1 mars 2016
 *      Author: joel
 */

#include <systemc.h>
#include "Block_Switching.h"
//#include "Bloc_Deswitching.h"
//#include "BDT_croisee.h"
//#include "register.h"
//#include "xor2.h"
//#include "Block_Routage.h"
//Declaration of struct
const int N = 5;
struct logic_vals { sc_logic a, b; } AB [N]=
{
		{ sc_logic(0), sc_logic(0) },
		{ sc_logic(0), sc_logic(1) },
		{ sc_logic(1), sc_logic(0) },
		{ sc_logic(1), sc_logic(0) },
		{ sc_logic(0), sc_logic(1) }

		};

int sc_main(int args, char* argv[]){

//////////////////////////---------- SIMULACION DE BLOQUE DE SWITCHING-----------------/////////////////////////
			module_Block_Switching B_Switching("B_Switching");
			sc_clock clk("clk", 10, 0.5, 0, true); // perido = 10 ns duty = 0.5, iniciar en 0 logico o en 1 logico, true = iniciar con rising edge false= iniciar con falling edge
			sc_signal < sc_logic > fil_j, fil_j1, fil_j_code, fil_j1_code, S_switch;
			B_Switching (clk, fil_j, fil_j1, S_switch, fil_j_code, fil_j1_code);

			sc_trace_file *tf;
			tf = sc_create_vcd_trace_file ("trace"); // creacion del fichero vcd para hacer el trace
			sc_trace (tf, clk, "clk"); // declaracion de la se~nales que ingresaran en el trace junto con sus respectivos labels
			sc_trace (tf, fil_j, "W1_IN");
			sc_trace (tf, fil_j1, "W2_IN");
			sc_trace (tf, fil_j_code, "W1_OUT");
			sc_trace (tf, fil_j1_code, "W2_OUT");
			sc_trace (tf, S_switch, "S_switch");
			//			W2
//			fil_j1 =sc_logic(0);
			//			W1
//			fil_j 	=sc_logic(1);
			//fil_j_code =sc_logic('1'); fil_j1_code =sc_logic('1');
//			sc_start (100, SC_NS);
//			cout << "W2 = " <<fil_j1_code << "  W1 = "<<fil_j_code <<"  Sw = "<< S_switch <<endl<<endl;
			sc_time t(11, SC_NS);    // duracion de la simulacion = 50 ns en cada bucle for
			for (int i = 0; i < N; i++ ) {
				//din.write(AB[i].din);
				fil_j1 = AB[i].a;
				fil_j = AB[i].b;
				sc_start(t);
				cout << "W2 = " <<fil_j1_code << "  W1 = "<<fil_j_code <<"  Sw = "<< S_switch <<endl<<endl;
			}
			sc_close_vcd_trace_file(tf); // fin del trace

//////////////////////////-- SIMULACION DE BLOQUE DE DETECTION DE TRANSMISION CROISEES----/////////////////////////
//		module_Bdt_croisee BDTC("BDTC");
//		sc_clock clk("clk", 10, 0.5, 0, false); // perido = 10 ns duty = 0.5, iniciar en 0 logico o en 1 logico, true = iniciar con rising edge false= iniciar con falling edge
//		sc_signal < sc_logic > fil_j, fil_j1, fil_j_code, fil_j1_code, S_switch;
//		BDTC (clk, fil_j, fil_j1, fil_j_code, fil_j1_code, S_switch);
//
//		sc_trace_file *tf;
//		tf = sc_create_vcd_trace_file ("trace"); // creacion del fichero vcd para hacer el trace
//		sc_trace (tf, clk, "clk"); // declaracion de la se~nales que ingresaran en el trace junto con sus respectivos labels
//		sc_trace (tf, fil_j, "fil_j");
//		sc_trace (tf, fil_j1, "fil_j1");
//		sc_trace (tf, fil_j_code, "fil_j_code");
//		sc_trace (tf, fil_j1_code, "fil_j1_code");
//		sc_trace (tf, S_switch, "S_switch");
//
//		fil_j =sc_logic('1'); fil_j1 =sc_logic('1');
//		fil_j_code =sc_logic('1'); fil_j1_code =sc_logic('1');
//		sc_start (50, SC_NS);
//		cout <<"switch= "<< S_switch <<endl<<endl;
////		sc_time t(50, SC_NS);    // duracion de la simulacion = 50 ns en cada bucle for
////		for (int i = 0; i < N; i++ ) {
////			//din.write(AB[i].din);
////			sc_start(t);
////			cout <<"clock= "<< clk <<endl<<endl;
////		}
//		sc_close_vcd_trace_file(tf); // fin del trace
/////////////////////////////////////----SIMULACION DE REGISTRO ------/////////////////////////////////////////////
//	module_register REG("REG");
//	sc_clock clk("clk", 10, 0.5, 0, false); // perido = 10 ns duty = 0.5, iniciar en 0 logico o en 1 logico, true = iniciar con rising edge false= iniciar con falling edge
//	sc_signal < sc_logic > din, dout;
//	REG (clk, din, dout);
//
//	sc_trace_file *tf;
//	tf = sc_create_vcd_trace_file ("trace"); // creacion del fichero vcd para hacer el trace
//	sc_trace (tf, clk, "clk"); // declaracion de la se~nales que ingresaran en el trace junto con sus respectivos labels
//	sc_trace (tf, din, "din");
//	sc_trace (tf, dout, "dout");
//
//	din=sc_logic('1');
//
//	sc_time t(50, SC_NS);    // duracion de la simulacion = 50 ns en cada bucle for
//	for (int i = 0; i < N; i++ ) {
//		din.write(AB[i].din);
//		sc_start(t);
//		cout <<"clock= "<< clk << "  "<< "entrada = "<<din<<"  "<< "salida = " << dout<<endl<<endl;
//	}
//	sc_close_vcd_trace_file(tf); // fin del trace

///////////////////////////-----------SIMULACION DE BLOCK DESWITCHING------////////////////////////////////////////

//	module_Block_Deswitching BR_DSW("BR_DSW");
//	sc_signal < sc_logic > fil_j, fil_j1, S_switch, fil_j_out, fil_j1_out;
//	BR_DSW (fil_j, fil_j1, S_switch, fil_j_out, fil_j1_out);
//
//	sc_trace_file *tf;
//	tf = sc_create_vcd_trace_file ("trace"); // creacion del fichero vcd para hacer el trace
//
//	sc_trace (tf, fil_j, "W1_IN");
//	sc_trace (tf, fil_j1, "W2_IN");
//	sc_trace (tf, fil_j_out, "W1_OUT");
//	sc_trace (tf, fil_j1_out, "W2_OUT");
//	sc_trace (tf, S_switch, "S_IN");
//
//	fil_j1 = sc_logic('0'); fil_j = sc_logic('0'); S_switch = sc_logic('1');
//	sc_start (10, SC_NS);
//	cout<< endl;
//	cout << "W2 = " <<fil_j1_out << "    "  <<"W1 = " <<fil_j_out;
//
//	fil_j1 = sc_logic('0'); fil_j = sc_logic('1'); S_switch = sc_logic('1');
//	sc_start (20, SC_NS);
//	cout<< endl;
//	cout << "W2 = " <<fil_j1_out << "    "  <<"W1 = " <<fil_j_out;
//
//
//	sc_close_vcd_trace_file(tf); // fin del trace

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////-----------SIMULACION DE BLOCK ROUTAGE-----////////////////////////////////////////

//	module_Block_Routage BR_DSW("BR_DSW");
//	sc_signal < sc_logic > fil_j, fil_j1, S_switch, fil_j_out, fil_j1_out;
//	BR_DSW (fil_j, fil_j1, S_switch, fil_j_out, fil_j1_out);
//
//	sc_trace_file *tf;
//	tf = sc_create_vcd_trace_file ("trace"); // creacion del fichero vcd para hacer el trace
//
//	sc_trace (tf, fil_j, "W1_IN");
//	sc_trace (tf, fil_j1, "W2_IN");
//	sc_trace (tf, fil_j_out, "W1_OUT");
//	sc_trace (tf, fil_j1_out, "W2_OUT");
//	sc_trace (tf, S_switch, "S_IN");
//
//	fil_j1 = sc_logic('0'); fil_j = sc_logic('0'); S_switch = sc_logic('1');
//	sc_start (10, SC_NS);
//	cout<< endl;
//	cout << "W2 = " <<fil_j1_out << "    "  <<"W1 = " <<fil_j_out;
//
//	fil_j1 = sc_logic('0'); fil_j = sc_logic('1'); S_switch = sc_logic('1');
//	sc_start (20, SC_NS);
//	cout<< endl;
//	cout << "W2 = " <<fil_j1_out << "    "  <<"W1 = " <<fil_j_out;
//
//
//	sc_close_vcd_trace_file(tf); // fin del trace

	return 0;
}
