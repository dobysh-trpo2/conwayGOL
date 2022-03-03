#include <iostream>
#include <vector>

using namespace std;

struct characherArray
{
    vector < vector <char> > array;
    int sizeX = 0;
    int sizeY = 0;
    void alloc()
    {
        array.resize(sizeY);
        for (int i = 0; i != sizeX; i++) {
            array[i].resize(sizeX);
        }

        cout << "successfully allocated \n";

    }

};

int main()
{
    characherArray field1;
    characherArray buffer1;
    int sizeX = 0;
    int sizeY = 0;

    cin >> sizeX;
    cin >> sizeY;

    field1.sizeX = sizeX;
    field1.sizeY = sizeY
    buffer1.sizeX = sizeX;
    buffer1.sizeY = sizeY;

    field1.alloc();
    buffer1.alloc();

    bool isRunning = true;

    int neighbors = 0;

    string userinput;
    int iterationAmount = 0;

    for (int i = 0; i != sizeY; i++) {
        for (int j = 0; j != sizeX; j++) {
            field1.array[i][j] = '.';
        }
    }

    while (isRunning == true) {

        // displaying the field
        for (int i = 0; i != sizeY; i++) {
            for (int j = 0; j != sizeX; j++) {
                cout << field1.array[i][j];
            }
            cout << endl;
        }

        // user input
        cin >> userinput;

        if (userinput == "close") {
            cout << endl;
            isRunning = false;
        }
	
		if (userinput == "set") {
        	int userX;
        	int userY;
        	
        	cin >> userX;
        	cin >> userY;
        	
        	if (userX < 0 || userX >= sizeX || userY < 0 || userY >= sizeY) {
        		cout << "value out of reach, try again \n";
        	} else {
        	
        	
	        	if (field1.array[userY][userX] == '.') {
	        		field1.array[userY][userX] = '#';
	        	} else {
	        		field1.array[userY][userX] = '.';
	        	}
        	}
        	
        }

        if (userinput == "run") {
            cout << endl;
            cin >> iterationAmount;

            for (int p = 0; p != iterationAmount; p++) {
                //calculating individual cells
                for (int i = 0; i != sizeY; i++) {
                    for (int j = 0; j != sizeX; j++) {
                    	
						/*
                        ////////////////////////
                        // -1,1  0,1  1,1
                        //
                        // -1,0  0,0  1,0
                        //
                        // -1,-1 0,-1 1,-1
                        ////////////////////////
						*/

                        //scanning for neighbors


                        for (int x = -1; x != 2; x++) {
                            for (int y = -1; y != 2; y++) {
								
								if (x != 0 || y != 0) {
								
                                if (j + x > 0 && j + x < sizeX && i + y > 0 && i + y < sizeY) {

	                                    if (field1.array[i + y][j + x] == '#') {
	                                        neighbors++;
	                                       // cout << neighbors;
	                                       // cout << endl;
	                                    }
                                }
                                    

                                }

                            }
                        }
                        if (neighbors == 3) {
                        	buffer1.array[i][j] = '#';
                        }
                        if (neighbors > 3) {
                        	buffer1.array[i][j] = '.';
                        }
                        if (neighbors < 2) {
                    		buffer1.array[i][j] = '.';
                        }
                        if (neighbors == 2) {
                        	buffer1.array[i][j] = field1.array[i][j];
                        }
                    	neighbors = 0;


                    }
                }
                
                for (int i = 0; i != sizeY; i++) {
                	for (int j = 0; j != sizeX; j++) {
                		field1.array[i][j] = buffer1.array[i][j];
                	}
                }
                
                
                
	            for (int i = 0; i != sizeY; i++) {
			            for (int j = 0; j != sizeX; j++) {
			                cout << field1.array[i][j];
			            }
			            cout << endl;
		    	    }
	                cout << endl;
	            }
        }
        
        
        
        if (userinput == "rand") {
          
          int temp = 0;
          
		  for (int i = 0; i != sizeY; i++) {
		  	
				for (int j = 0; j != sizeX; j++) {
				            
				    temp = rand() % 2;
				            
				    if (temp == 1) {
				    	field1.array[i][j] = '#';
				    } else {
				    	field1.array[i][j] = '.';
				    }
				            
				            
		   	 }
		    }
        }

    }



    return 0;
}
