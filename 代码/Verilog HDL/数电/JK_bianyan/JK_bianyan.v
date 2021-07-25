module JK_bianyan(clk,J,K,Q);
input clk,J,K;
output Q;
reg Q;
always @(posedge clk)
	case ({J,K})
	2'b00:Q<=Q;
	2'b01:Q<=1'b0;
	2'b10:Q<=1'b1;
	2'b11:Q<=~Q;
	default:Q=Q;
	endcase 
	
endmodule 