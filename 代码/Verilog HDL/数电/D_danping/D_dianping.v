module D_dianping(C,D,Q);
	input C,D;
	output  Q;
	
	assign Q=C?D:Q;
			
endmodule 