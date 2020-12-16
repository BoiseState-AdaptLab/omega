all:
	cd omega_lib/obj; make
	cd code_gen/obj; make
	cd omega_calc/obj; make
clean:
	cd omega_lib/obj; $(MAKE) clean
	cd code_gen/obj; $(MAKE) clean
	cd omega_calc/obj; $(MAKE) clean


