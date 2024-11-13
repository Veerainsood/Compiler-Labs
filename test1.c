int global_var = 100;       
int common_var = 50;        
int counter;                
{
    int level1_var = 10;    
    counter = level1_var;   

    if (global_var > level1_var) {
        int common_var = 20;
        {
            int level2_var = 5;
            float temp = common_var + level2_var;
            
            while (temp < global_var) {
                temp += 15;
                level2_var++;  

                if (temp > 75) {
                    int level3_var = level1_var + temp;
                    level2_var = level3_var - level2_var;
                    {
                        float level4_var = 2 * level3_var; 
                        temp += level4_var;

                        if (level4_var > 0) {
                            common_var += 1; 
                            undeclared_var = 5; 
                        }
                    }
                }
            }
        }
        
        level2_var = 30;
    }

    while (counter < 5) {
        int loop_var = 3 * counter; 
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
