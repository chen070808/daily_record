module D_bianyan(clk,D,Q);
	input clk,D;
	output Q;
	reg Q;
	always @(posedge clk)
		Q<=D; 
	
endmodule 