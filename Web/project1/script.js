function Consonants() {
    let name = document.getElementById("inputName").value;
    let surname = document.getElementById("inputSurname").value;
    let day = document.getElementById("day").value
    let month = document.getElementById("month").value
    let year = document.getElementById("year").value
    document.write("Risultato: ")
    let count = 0
        for (let i = 0; i < name.length; i++) {
            if (name[i] != "a" && name[i] != "e" && name[i] != "i" && name[i] != "o" && name[i] != "u" && count != 3) {
                document.write(name[i])
                count++
            }
        }
    count = 0
    for (let i = 0; i < surname.length; i++) {
        if (surname[i] != "a" && surname[i] != "e" && surname[i] != "i" && surname[i] != "o" && surname[i] != "u" && count != 3) {
            document.write(surname[i])
            count++
        }
    }
    document.write(day)
    document.write(month)
    document.write(year)
}

