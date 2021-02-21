function Consonants() {
    var name = document.getElementById("inputName").value;
    document.write("Le consonanti trovate nel nome sono: ")
    for (var i = 0; i < name.length; i++) {
            if (name.charAt(i) != "a" && name.charAt(i) != "e" && name.charAt(i) != "i" && name.charAt(i) != "o" && name.charAt(i) != "u") {
                document.write(name.charAt(i))
            }
        }
    }