#include "neuralnetwork.hh"

#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX_ERROR 0.1
#define INPUT_LENGTH 784
#define OUTPUT_LENGTH 10
#define TRAINING_SET_SIZE 10

NeuralNetwork::NeuralNetwork(int size_of_input_layer, int size_of_hidden_layer, int size_of_output_layer) {

input_layer = new float* [TRAINING_SET_SIZE];
output_layer = new float* [TRAINING_SET_SIZE];
hidden_layer = new float [size_of_hidden_layer];

bias = new float [size_of_hidden_layer+size_of_output_layer];

number_of_biases=size_of_hidden_layer+size_of_output_layer;

for(int i=0; i<size_of_hidden_layer+size_of_output_layer; i++)
bias[i]=(((rand() % 1000000) / 1700.0) - 9.8)*0.0015;

input_patterns = new float* [TRAINING_SET_SIZE];
output_patterns = new float* [TRAINING_SET_SIZE];

hidden_errors = new float [size_of_hidden_layer];
output_errors = new float [size_of_output_layer];

for(int i=0; i<TRAINING_SET_SIZE; i++) {

    input_layer[i] = new float [INPUT_LENGTH];
    output_layer[i] = new float [OUTPUT_LENGTH];

}

for(int i=0; i<TRAINING_SET_SIZE; i++) {

    input_patterns[i] = new float [INPUT_LENGTH];
    output_patterns[i] = new float [OUTPUT_LENGTH];

}


eta=0.5;

tmp1 = tmp2 = 0.0;

layer_sizes[0] = size_of_input_layer;
layer_sizes[1] = size_of_hidden_layer;
layer_sizes[2] = size_of_output_layer;

W = new float** [3];

for(int i=0; i<3; i++) {

W[i] = new float* [layer_sizes[i]];

    for(int j=0; j<layer_sizes[i]; j++) {

    if(i==0)
    W[i][j] = new float [1];
    else
    W[i][j] = new float [layer_sizes[i-1]];

    }
}

for(int i=1; i<3;i++) {
    for(int j=0; j<layer_sizes[i]; j++) {
        for(int k=0; k<layer_sizes[i-1]; k++) {

            W[i][j][k] =  (((rand() % 1000000) / 1700.0) - 9.8)*0.0015;
            if(W[i][j][k] == 0.0)
            W[i][j][k] = 0.01492;

        }
    }
}

}

NeuralNetwork::~NeuralNetwork() {

for(int i=0; i<TRAINING_SET_SIZE; i++) {

    delete []input_patterns[i];
    delete []output_patterns[i];

}

for(int i=0; i<TRAINING_SET_SIZE; i++) {

    delete []input_layer[i];
    delete []output_layer[i];

}

delete []input_layer;
delete []output_layer;

delete []bias;

delete []input_patterns;
delete []output_patterns;

delete []output_errors;
delete []hidden_errors;


for(int i=0; i<layer_sizes[0]; i++)
delete [] W[0][i];

for(int i=0; i<layer_sizes[1]; i++)
delete [] W[1][i];

for(int i=0; i<layer_sizes[2]; i++)
delete [] W[2][i];

delete [] W[0];
delete [] W[1];
delete [] W[2];

delete [] W;


}

void NeuralNetwork::load_training_set(std::vector<std::string> input_data_file_names, std::vector<std::string> output_data_file_names) {

std::ifstream input_data;
std::ifstream output_data;

unsigned char pixel;
float input_value = 0.0;
float output_value = 0.0;

for(int f=0; f<10; f++) {

    input_data.open(input_data_file_names.at(f), std::ios::binary);
    output_data.open(output_data_file_names.at(f), std::ios::in);

    if(input_data.good() && output_data.good()) {


        for(unsigned int i=0; i<INPUT_LENGTH; i++) {

            input_data>>pixel;
            input_value = (float) pixel;
            if(input_value>0)
            input_value = 1;

            input_patterns[f][i]=input_value;
            input_layer[f][i]=input_value;

        }

        for(unsigned int i=0; i<OUTPUT_LENGTH; i++) {

            output_data>>output_value;
            output_patterns[f][i] = output_value;

        }


    input_data.close();
    output_data.close();

    }
    else
    std::cout<<"Nie uzyskano dostępu do zestawu uczącego, przerwano odczyt danych"<<std::endl;

}

std::cout<<"Wczytano dane treningowe."<<std::endl;

}


void NeuralNetwork::learn() {

std::cout<<"Trwa uczenie..."<<std::endl;

while(!check_if_answer_is_correct()) {

for(int i=0; i<TRAINING_SET_SIZE; i++) {
			forward_pass(i);
			backward_pass(i);
		}
}

		if(check_if_answer_is_correct())
			std::cout<<"Nauka została zakończona"<<std::endl;
        else
            std::cout<<"Nauka nie została zakończona, należy spróbować ponownie."<<std::endl;
}


void NeuralNetwork::forward_pass(int pattern) {

	float tmp=0;

    /* Propagacja w przód z warstwy wejściowej do warstwy ukrytej */
	for(int i=0; i<layer_sizes[1]; i++) {
		for(int j=0; j<layer_sizes[0]; j++) {
			tmp += (input_layer[pattern][j] * W[1][i][j]);
		}
		hidden_layer[i] = activation_function(tmp + bias[i]);
		tmp = 0;
	}

    /* Propagacja w przód z warstwy ukrytej do warstwy wyjściowej */
	for(int i=0; i<layer_sizes[2]; i++) {
		for(int j=0; j<layer_sizes[1]; j++) {
			tmp += (hidden_layer[j] * W[2][i][j]);
		}
		output_layer[pattern][i] = activation_function(tmp + bias[i + layer_sizes[1]]);
		tmp = 0;
	}

}

void NeuralNetwork::backward_pass(int pattern) {

	float tmp = 0;

    /* Wyliczanie błędów na wyjściu */
	for(int i=0; i<layer_sizes[2]; i++)
		output_errors[i] = (output_patterns[pattern][i] - output_layer[pattern][i]);

    /* Wyliczanie błędów na warstwie ukrytej */
	for(int i=0; i<layer_sizes[1]; i++) {
		for(int j=0; j<layer_sizes[2]; j++) {
			tmp += (output_errors[j] * W[2][j][i]);
		}
	hidden_errors[i] = hidden_layer[i] * (1-hidden_layer[i]) * tmp;
	tmp = 0.0;
	}

    /* Dostosowywanie wag warstw ukrytej i wyjściowej */
	float length = 0.0;
	for (int i=0; i<layer_sizes[1]; i++)
		length += hidden_layer[i]*hidden_layer[i];

	if (length<=0.1) length = 0.1;
	for(int i=0; i<layer_sizes[1]; i++) {
		for(int j=0; j<layer_sizes[2]; j++) {
			W[2][j][i] += (eta * output_errors[j] * hidden_layer[i] / length);
		}
	}

    /* Dostosowywanie biasów warstwy ukrytej */
	for(int i=layer_sizes[1]; i<number_of_biases; i++)
		bias[i] += (eta * output_errors[i] / length);


    /* Dostosowywanie wag warstw wejściowej i ukrytej */
	length = 0.0;
	for (int i=0; i<layer_sizes[0]; i++)
		length += input_layer[pattern][i]*input_layer[pattern][i];

	if (length<=0.1) length = 0.1;
	for(int i=0; i<layer_sizes[0]; i++) {
		for(int j=0; j<layer_sizes[1]; j++) {
			W[1][j][i] += (eta * hidden_errors[j] * input_layer[pattern][i] / length);
		}
	}

    /* Dostosowywanie biasów warstwy wyjściowej */
	for(int i=0; i<layer_sizes[1]; i++)
		bias[i] += (eta * hidden_errors[i] / length);

}

bool NeuralNetwork::check_if_answer_is_correct() {

	float tmp, error = 0.0;
	tmp = output_patterns[tmp1][tmp2] - output_layer[tmp1][tmp2];
	if (tmp<0)
        error -= tmp;
	else
        error += tmp;

	if(error > MAX_ERROR)
	return 0;

	error = 0.0;
	for(int i=0; i<TRAINING_SET_SIZE; i++) {
		for(int j=0; j<layer_sizes[2]; j++) {
			tmp = output_patterns[i][j] - output_layer[i][j];
			if (tmp<0)
                error -= tmp;
			else
                error += tmp;
            std::cout<<error<<" "<<std::endl;
			if(error>MAX_ERROR) {
				tmp1 = i;
				tmp2 = j;
				return 0;
			}
			error = 0.0;
		}
	}
	return 1;

}

void NeuralNetwork::recognize(std::vector<std::string> test_data_file_names) {

    std::ifstream test_data;
 //   unsigned char pixel;
  //  float test_value;
 //   bool read_flag=0;

    test_data.open(test_data_file_names.at(1), std::ios::binary);

//for(int f=0; f<10; f++) {

 /*   if(input_data.good() && output_data.good()) {
        read_flag=1;
        for(int num=0; num<2; nym++)
        for(int i=0; i<INPUT_LENGTH; i++) {

            test_data>>pixel;
            test_value = (float) pixel;
            if(test_value>0)
            test_value = 1;

            input_layer[f][i]=test_value;

        }


    }
    else
    std::cout<<"Nie uzyskano dostępu do zestawu uczącego, przerwano odczyt danych"<<std::endl;
*/
    if(1) {

    forward_pass(1);

	std::cout<<"Wyjścia sieci: "<< std::endl;
	for(int i=0; i<layer_sizes[2]; i++)
		std::cout<<output_layer[1][i] <<"   ";


    }

//}


}

float NeuralNetwork::activation_function(float input) {
  return 1.0/(1.0+exp(((-1)*input)));
}
