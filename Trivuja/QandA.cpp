//
//  QandA.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 27/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include "QandA.h"


/**@brief:constructor de QandA que crea la pregunta con las tres respuestas asociadas a ella
 * @param:la pregunta(string),las respuestas(vector de tres strings), y la respuesta correcta(int)
 * @pre:la respuesta correcta(0-2)
 * @post:ninguna
 
 */
QandA::QandA(string quest, string answ[], int cA){
    question=quest;
    for (int i=0; i<3; i++) {
        answer[i]=answ[i];
    }
    correctAnswer=cA;
}

/**@brief:función que compruba si la respuesta es correcta o no
 * @param: el numero de la respuesta(int)
 * @pre:answ(0-2)
 * @post:ninguna
 * @ret:valor logico true(si es correcta) y false(si no es correcta)
 
 */

bool QandA::isCorrect(int answ){
    if (answ==correctAnswer) {
        return true;
    }
    else{
        return false;
    }
}

/**@brief:obtiene una pregunta 
 * @param:ninguno
 * @pre:niguna 
 * @post:ninguna
 
 */

string QandA::getQuestion(){
    return question;
}

/**@brief:obtine la  respuestas de una pregunta
 * @param:el numero de respuesta 
 * @pre:nAns(0-2)
 * @post:ninguna
 
 */
string QandA::getAnswer(int nAns){
    return answer[nAns];
}