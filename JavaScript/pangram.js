function checkPangramString(string){
    let isPangram = false;

    const lowerCasedSentence = string.toLowerCase();
    const letters = lowerCasedSentence.match(/[a-z]/g);
    const uniqueLetters = new Set(letters) 

    if (uniqueLetters.size === 26){
        isPangram = true
    }

    if(isPangram){
        return "Pangram sentence";
    } else {
        return "Not Pangram sentence";
    }
}
