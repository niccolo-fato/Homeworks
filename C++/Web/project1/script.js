function findConsonants(){
    var name = document.f1.n1.value;
    var vocali="aeiou"
    var consonanti = ""
    for (var i=0; i<name.length; i++){
        if(vocali.indexOf(name[i])!= -1){
            consonanti+= nome[i] + ","
        }
    }
    document.getElementById("cons").innerHTML = "Le consonanti trovate sono: " + consonanti
}