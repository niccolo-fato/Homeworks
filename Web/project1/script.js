function Consonants() {
    let name = document.getElementById("inputName").value;
    let surname = document.getElementById("inputSurname").value;
    document.write("Le consonanti trovate nel nome sono: ")
    for (let i = 0; i < name.length; i++) {
        if (name[i] != "a" && name[i] != "e" && name[i] != "i" && name[i] != "o" && name[i] != "u") {
            document.write(name[i])
        }
    }
    document.write("<br> Le consonanti trovate nel cognome sono: ")
    for (let i = 0; i < surname.length; i++) {
        if (surname[i] != "a" && surname[i] != "e" && surname[i] != "i" && surname[i] != "o" && surname[i] != "u") {
            document.write(surname[i])
        }
    }
}

