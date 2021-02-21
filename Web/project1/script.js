function Consonants() {
    var name = document.getElementById("inputName").value
    var surname = surname = document.getElementByld("inputSurname").value
    document.write("Le consonanti trovate nel nome sono: ")
    for (var i = 0; i < name.length; i++) {
            if (name.charAt(i) != "a" && name.charAt(i) != "e" && name.charAt(i) != "i" && name.charAt(i) != "o" && name.charAt(i) != "u") {
                document.write(name.charAt(i))
            }
        }
    }
    document.write("Le consonanti trovate nel cognome sono: ")
    for (var i = 0; i < surname.length; i++) {
            if (surname.charAt(i) != "a" && surname.charAt(i) != "e" && surname.charAt(i) != "i" && surname.charAt(i) != "o" && surname.charAt(i) != "u") {
                document.write(surname.charAt(i))
            }
        }
