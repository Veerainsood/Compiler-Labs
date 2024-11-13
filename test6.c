int n=10;
for(int i=0;i<n;i++)
{
    int loop_var =0;
    float level1_var =0;
    while (counter < 5) {
        float loop_var = 3 * counter; 
        counter++;

        if (loop_var > level1_var) {
            undeclared_var2 = loop_var; 

            {
                int inner_scope_var = 10;   

                while (inner_scope_var > 0) {
                    inner_scope_var--;

                    if (counter > 2) {
                        int common_var = 5;
                        counter += common_var;
                    }
                }
            }
        }
    }
}