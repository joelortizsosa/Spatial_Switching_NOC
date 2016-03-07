/*
 * nand3.h
 *
 *  Created on: 3 mars 2016
 *      Author: joel
 */

#include <systemc.h>

SC_MODULE(module_nand) {
    sc_in <sc_logic> a, b, c;
    sc_out<sc_logic> F;

    void methode_nand() {
        F.write(~(a.read() & b.read() & c.read()) );
    }

    SC_CTOR(module_nand) {
        SC_METHOD(methode_nand);

        sensitive << a << b << c;
        dont_initialize();
    }
};
