function findConsonants(){
    const name = document.getElementById("inputName").value;
    const consonantsList = 'cdfghjklmnpqrstvwxyz';
    var contLetters = 0;
    var out = '';

    for (var i=0; i<name.length; i++)
        if (consonantsList.indexOf(name[i]) != -1){
            contLetters++;
            out += name[i] + ",";
        }
        document.getElementById("outputLetters").innerHTML = out;
        document.getElementById("outputNumber").innerHTML = "Sono " + contLetters + " lettere.";

}