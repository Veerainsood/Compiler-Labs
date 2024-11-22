module quest6_d;


reg a1;
reg b1;
reg c1;
wire w1;
wire w2;
wire w3;
wire w4;
wire w5;
wire w6;
wire w7;
wire w8;
wire w9;



andgate ar(.x(a1),.y(b1),.z(w1));
notgate ar1(.x(a1),.z(w2));
andgate ar2(.x(w2),.y(c1),.z(w3));
andgate ar3(.x(b1),.y(c1),.z(w4));
orgate ar4(.x(w1),.y(w3),.z(w5));
orgate ar5(.x(w5),.y(w4),.z(w6));

andgate ar6(.x(a1),.y(b1),.z(w7));
andgate ar7(.x(w2),.y(c1),.z(w8));
orgate ar8(.x(w7),.y(w8),.z(w9));

  



initial begin
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

