module quest6_c;


reg a1;
reg b1;
reg c1;
wire w1;
wire w2;
wire w3;
wire w4;
wire w5;  

orgate ar(.x(b1),.y(c1),.z(w1));
andgate ar1(.x(w1),.y(a1),.z(w4));

andgate ar2(.x(a1),.y(b1),.z(w2));
andgate ar3(.x(a1),.y(c1),.z(w3));
orgate ar4(.x(w2),.y(w3),.z(w5));

initial 
begin
a1=1'b0; b1=1'b0;c1=1'b0; #20
a1=1'b0; b1=1'b0;c1=1'b1; #20
a1=1'b0; b1=1'b1;c1=1'b0; #20
a1=1'b0; b1=1'b1;c1=1'b1; #20
a1=1'b1; b1=1'b0;c1=1'b0; #20
a1=1'b1; b1=1'b0;c1=1'b1; #20
a1=1'b1; b1=1'b1;c1=1'b0; #20
a1=1'b1; b1=1'b1;c1=1'b1; 

end
endmodule