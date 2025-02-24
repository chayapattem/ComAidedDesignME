#include <string>
#include <stack>
#include <unordered_map>
#include <math.h>
#include <vector>

namespace COMAID{

        class Operator_Operand{
            public:
                bool isOperator;
                std::string str;
                int Required_operand;
                int outPriority;
                int inPriority;
                float value;

            Operator_Operand(){
                //Default Constructor
                this->isOperator = false;
                this->str = "";
                this->Required_operand = 0;
                this->outPriority = 0;
                this->inPriority = 0;
                this->value = float();

            }

            Operator_Operand(float value){
                //Operand Handle constructor
                this->isOperator = false;
                this->str = "";
                this->Required_operand = 0;
                this->outPriority = 0;
                this->inPriority = 0;
                this->value = value;
            }

            Operator_Operand(int value){
                this->isOperator = false;
                this->str = "";
                this->Required_operand = 0;
                this->outPriority = 0;
                this->inPriority = 0;
                this->value = (float) value;
            }

            Operator_Operand virtual calculated(Operator_Operand a , Operator_Operand b){
                return 0;
            }

            Operator_Operand virtual calculated(Operator_Operand a){
                return 0;
            }
        };

        class plus : public Operator_Operand{
            public:
                plus(){
                    this->isOperator = true;
                    this->str = "+";
                    this->Required_operand = 2;
                    this->outPriority = 2;
                    this->inPriority = 3;
                    this->value = 0;
                }
                Operator_Operand calculated(Operator_Operand a , Operator_Operand b) override {
                    return Operator_Operand(a.value+b.value);
                }
        };

        class minus : public Operator_Operand{
            public:
                minus(){
                    this->isOperator = true;
                    this->str = "-";
                    this->Required_operand = 2;
                    this->outPriority = 2;
                    this->inPriority = 3;
                    this->value = 0;
                }
                Operator_Operand calculated(Operator_Operand a , Operator_Operand b) override {
                    return Operator_Operand(a.value-b.value);
                }
        };

        class multipy : public Operator_Operand{
            public:
                multipy(){
                    this->isOperator = true;
                    this->str = "*";
                    this->Required_operand = 2;
                    this->outPriority = 4;
                    this->inPriority = 5;
                    this->value = 0;
                }

                Operator_Operand calculated(Operator_Operand a , Operator_Operand b) override {
                    return Operator_Operand(a.value*b.value);
                }
        };

        class devide : public Operator_Operand{
            public:
                devide(){
                    this->isOperator = true;
                    this->str = "/";
                    this->Required_operand = 2;
                    this->outPriority = 4;
                    this->inPriority = 5;
                    this->value = 0;
                }

                Operator_Operand calculated(Operator_Operand a , Operator_Operand b) override {
                    return Operator_Operand(a.value/b.value);
                }
        };

        class power : public Operator_Operand{
            public:
                power(){
                    this->isOperator = true;
                    this->str = "^";
                    this->Required_operand = 2;
                    this->outPriority = 8;
                    this->inPriority = 7;
                    this->value = 0;
                }

                Operator_Operand calculated(Operator_Operand a , Operator_Operand b) override {
                    return Operator_Operand(pow(a.value,b.value));
                }
        };

        class open_parentheses : public Operator_Operand{
            public:
                open_parentheses(){
                    this->isOperator = true;
                    this->str = "(";
                    this->Required_operand = 0;
                    this->outPriority = 9;
                    this->inPriority = 0;
                    this->value = 0;
                }
        };

        class close_parentheses : public Operator_Operand{
            public:
                close_parentheses(){
                    this->isOperator = true;
                    this->str = ")";
                    this->Required_operand = 0;
                    this->outPriority = 1;
                    this->inPriority = 0;
                    this->value = 0;
                }

        };

        class sin : public Operator_Operand{
            public:
                sin(){
                    this->isOperator = true;
                    this->str = "sin";
                    this->Required_operand = 1;
                    this->outPriority = 9;
                    this->inPriority = 0;
                    this->value = 0;
                }
                Operator_Operand calculated(Operator_Operand a ) override {
                    return Operator_Operand( std::sin(a.value) );
                }
        };

        class cos : public Operator_Operand{
            public:
                cos(){
                    this->isOperator = true;
                    this->str = "cos";
                    this->Required_operand = 1;
                    this->outPriority = 9;
                    this->inPriority = 0;
                    this->value = 0;
                }
                Operator_Operand calculated(Operator_Operand a ) override {
                    return Operator_Operand(std::cos(a.value));
                }
        };

        class tan : public Operator_Operand{
            public:
                tan(){
                    this->isOperator = true;
                    this->str = "tan";
                    this->Required_operand = 1;
                    this->outPriority = 9;
                    this->inPriority = 0;
                    this->value = 0;
                }
                Operator_Operand calculated(Operator_Operand a ) override {
                    return Operator_Operand(std::tan(a.value));
                }
        };

        class sinh : public Operator_Operand{
            public:
                sinh(){
                    this->isOperator = true;
                    this->str = "sinh";
                    this->Required_operand = 1;
                    this->outPriority = 9;
                    this->inPriority = 0;
                    this->value = 0;
                }
                Operator_Operand calculated(Operator_Operand a ) override {
                    return Operator_Operand(std::sinh(a.value));
                }
        };

        class cosh : public Operator_Operand{
            public:
                cosh(){
                    this->isOperator = true;
                    this->str = "cosh";
                    this->Required_operand = 1;
                    this->outPriority = 9;
                    this->inPriority = 0;
                    this->value = 0;
                }
                Operator_Operand calculated(Operator_Operand a ) override {
                    return Operator_Operand(std::cosh(a.value));
                }
        };

        class tanh : public Operator_Operand{
            public:
                tanh(){
                    this->isOperator = true;
                    this->str = "tanh";
                    this->Required_operand = 1;
                    this->outPriority = 9;
                    this->inPriority = 0;
                    this->value = 0;
                }
                Operator_Operand calculated(Operator_Operand a ) override {
                    return Operator_Operand(std::tanh(a.value));
                }

        };

        class ln : public Operator_Operand{
            public:
                ln(){
                    this->isOperator = true;
                    this->str = "ln";
                    this->Required_operand = 1;
                    this->outPriority = 9;
                    this->inPriority = 0;
                    this->value = 0;
                }
                Operator_Operand calculated(Operator_Operand a ) override {
                    return Operator_Operand(std::log(a.value));
                }
        };

        std::vector<Operator_Operand *> infix2postfix(std::vector<Operator_Operand *> &infix){ // Don't change value of Operator_operand Object
            int n = infix.size();
            std::vector<Operator_Operand *> postfix;
            std::stack<Operator_Operand *> s;

            for (int i=0 ; i < n ; i++ ) {
                Operator_Operand * token_ptr = infix[i];
                if (! (token_ptr->isOperator)) {
                    postfix.push_back(token_ptr);
                }
                else {
                    int p = token_ptr->outPriority;
                    while( !s.empty() && s.top()->inPriority >= p ) {
                        postfix.push_back(s.top()); s.pop();
                    }
                    if (token_ptr->str == ")") {
                        s.pop(); 
                        if (!s.empty() && s.top()->Required_operand == 1){
                            postfix.push_back(s.top()); s.pop();
                        }
                    }
                    else s.push(token_ptr);
                }
            }
            while(!s.empty()) { postfix.push_back(s.top()); s.pop();}
            return postfix; // Make sure to delete all infix object that can cause MemoryLeak
        }
        Operator_Operand calculated_postfix(std::vector<Operator_Operand *> postfix){
            std::stack<Operator_Operand *> s;
            std::vector<Operator_Operand *> tmp_created_object;
            for (int i = 0 ; i < postfix.size() ; i++){
                if ( !(postfix[i]->isOperator) ) s.push(postfix[i]);
                else {
                    Operator_Operand tmp;
                    if (postfix[i]->Required_operand == 1){
                        Operator_Operand * a = s.top(); s.pop();
                        tmp = postfix[i]->calculated(*a);
                        
                    }
                    else if (postfix[i]->Required_operand == 2){
                        Operator_Operand * b = s.top(); s.pop();
                        Operator_Operand * a = s.top(); s.pop();
                        tmp = postfix[i]->calculated(*a,*b);
                    }
                    Operator_Operand * new_obj_ptr = new Operator_Operand(tmp.value);
                    tmp_created_object.push_back(new_obj_ptr);
                    s.push(new_obj_ptr);
                }
            }
            //Delete tmp
            Operator_Operand out = *s.top();
            for (auto i:tmp_created_object){
                delete i;
            }
            return out;

        }

        float calculate(std::vector<Operator_Operand *> &eqn){
            return calculated_postfix(infix2postfix(eqn)).value;
        }

}
