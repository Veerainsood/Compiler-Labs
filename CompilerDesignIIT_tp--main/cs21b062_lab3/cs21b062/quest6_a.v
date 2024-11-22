module quest6_a;


reg a1;
reg b1;

reg c1;
reg d1;

wire w1;
wire w2;
wire w3;
wire w4;
wire w5;


notgate ar(.z(w1),.x(a1));
notgate ar1(.z(w2),.x(b1));

orgate ar2(.z(w3),.x(w1), .y(w2));



orgate br1(.z(w4),.x(a1), .y(b1) );
notgate br2( .z(w5),.x(w4));



initial begin
a1 = 1'b0; b1 = 1'b0; #20;
a1 = 1'b0; b1 = 1'b1; #20;
a1 = 1'b1; b1 = 1'b0; #20;
a1 = 1'b1; b1 = 1'b1; 

end 
endmodule 
