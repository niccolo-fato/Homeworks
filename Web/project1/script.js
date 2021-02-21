function findConsonants(){
    var name = document.getElementById("inputName").value;
    var consonanti = ""
    for (var i=0; i<name.length; i++){
        if(name.charAt(i) != "a"){
            consonanti+= nome[i] + ","
        }
    }
    document.write("Le consonanti trovate sono: " + consonanti)
}