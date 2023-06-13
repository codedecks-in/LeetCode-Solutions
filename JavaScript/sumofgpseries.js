function sumOfGpSeries(firstTerm, commonRatio, numOfTerms){
    if(Number.isFinite(numOfTerms)){
        if(commonRatio === 1) return firstTerm*numOfTerms;
        else{
            return (firstTerm*(Math.pow(commonRatio, numOfTerms)-1))/(commonRatio -1);
        }
    }
    else{
        if(Math.abs(commonRatio)<1)
            return firstTerm/(1-commonRatio);
        else
        {
            throw 'The Geometric progression is diverging and hence its sum cannot be calculated';
        }
    }
}
console.log(sumOfGpSeries(1, 1, 5))
