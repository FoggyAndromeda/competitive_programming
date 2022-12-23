vol, cov, f, s = map(int, input().split())

if (f < s):
    count_books = s - f
    print(vol * (count_books - 1) + 2 * count_books * cov)
else:
    count_books = f - s + 1
    print(vol * count_books + 2 * cov * (count_books - 1))