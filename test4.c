int main_var = 10;           
int shadow_test = 5;         
int another_var = 20;        

{
    int nested_var = main_var + shadow_test;  
    int counter = 0;           

    while (counter < 3) {
        counter++;             
        int shadow_test = 50;  

        if (nested_var < 100) {
            int deep_var1 = nested_var + shadow_test;  

            while (deep_var1 > 0) {
                int shadow_test = 25;                  
                deep_var1 -= 10;
                
                if (deep_var1 % 2 == 0) {
                    int inner_count = counter + deep_var1;  
                    main_var += inner_count;                

                    {
                        int deepest_var = inner_count * 2;  
                        inner_count += shadow_test;         
                        undeclared_var1 += deepest_var;     

                        if (deepest_var > 100) {
                            shadow_test += 3;              
                        } else {
                            int loop_breaker = deepest_var - inner_count;
                            if (loop_breaker > 0) {
                                
                            }
                        }
                    }
                }
            }

            
        }
    }
    int a[10][20][30];
    deep_var1 = 500;           
    recursive_scope = 100;     
}
