module and_nor(input x, input y, output z);


wire c1;
wire c2;
///wire c3;

norgate ar( .x(a1), .y(a1), .z(c1));
norgate ar1( .x(b1), .y(b1), .z(c2));
norgate ar2( .x(c1), .y(c2), .z(z));


endmodule


