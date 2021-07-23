module T_dianping(C,T,Q,rst);
input C,T,rst;
output Q;
reg Q;

always @(*)
begin
	if(rst==1'b0)
	Q=1'b0;
	else 
	Q=Q;
	if(C==1'b1&&T==1'b1)
	Q=~Q;
	else 
	Q=Q;
end

endmodule 