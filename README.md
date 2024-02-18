# Random Equation I Found on the Internet

Evidently, I spent way too much time on youtube—and not enough time on doing my job.

Recently, I came accross [this video](https://www.youtube.com/watch?v=zdAJXil-NvA) which talked about a mathematical puzzle: given `x+y=8`, what is the maximum value of `x^y`?
For some reason the thumbnail intrigued me and makes me think, what if I do this for other numbers?

So I wrote a C++ program to do that, as one does, resulting in **clixpo.cpp** (compiled with g++ into `clixpo`). The videos itself talk about decimal/fractional exponents which I never really grasped so I noped out and wrote the program to just care about _Whole_ numbers instead of Real numbers. It would be way too much of a hassle to learn the entire concept of computing fractional exponents. Oh and also I'm limiting the program to positive numbers because, as the video noted, the maximum if we include negative numbers would approach `(-inf)^inf`.

And then I noticed a weird pattern when doing it for numbers above 8. If you limit yourself to whole numbers, the maximum value for `x+y=8` is `4^4=256`, 4 is exactly half of 8. For number above 8, the number shifts to `x<(x+y)/2`. I wrote a second program that outputs into stdout in *.csv-compatible format—hence, **csvxpo.cpp** (compiled with g++ into `csvxpo`). I then ran it for `x+y=100` and shunt the stdout to puzzl.csv, and run it again for `x+y=200` and shunt the stdout to puzzl2.csv. Sure enough, when I plotted the two (puzzl.xlsx and Demonstration.png) the graph showed peak on around `x~=(x+y)/4` i.e. x being 25% of `x+y`.

![Two graphs showing the trend for larger number to shift their peaks to earlier values](/Demonstration.png "Shifting peaks")

I wrote a final program **trendxpo.cpp** (compiled with g++ into `trendpx`) which outputs `(x/(x+y))*100%` to stdout and then I ran a bash command `for ((i=1; i<=231; i++)); do ./trenpx $i >> trend.csv; done`. I then plotted the output (trend.xlsx and Trends.png) to show...a fractional base logarithmic graph? I have no idea idk about math. I only ran it up to 231 because at i=232 onwards I hit the limit of a `double` for the result of `x^y`—which isn't strictly a problem, I can just make **trendxpo.cpp** operates on `longdouble` instead of regular `double`, but there's really no point in that. The pattern holds.

![Graph demonstrating the pattern](/Trends.png "The Pattern Holds")
