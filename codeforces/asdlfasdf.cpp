
const https = require('https');
/*
 * Complete the function below.
 * Use console.log to print the result, you should not return from the function.
 */
function getMovieTitles(substr) {
    let url = 'https://jsonmock.hackerrank.com/api/movies/search/?Title=' + substr + "&page=" + 1;
    https.get(url, (res) => {
        res.on('data', function(body) {
            let data = JSON.parse(body);
            let movieList = data.data;
            let totPages = data.total_pages;
            let myArray = [];
            movieList.map((list) => {
              myArray.push(list.Title)
            })
            for (let i = 2; i <= totPages; i++) {
                let newPage = i;
                let newUrl = 'https://jsonmock.hackerrank.com/api/movies/search/?Title=' + substr + "&page=" + newPage;
                https.get(newUrl, (nowRes) => {
                    nowRes.on('data', function(body) {
                        let newData = JSON.parse(body);
                        let newMovies = newData.data;
                        for (let i = 0; i < newMovies.length; i++) {
                            myArray.push(newMovies[i].Title);
                        }
                        myArray.sort();
                        let length = myArray.length;
                        for(var j = 0; j < length; j++) {
                            console.log(myArray[j]);
                        }
                        myArray = [];
                    })
                })
            }

        })

    })

}
