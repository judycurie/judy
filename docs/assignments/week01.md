# **Week01.** Principles and practices

|Assignment    |                          |
| ----------- | ------------------------------------ |
| *group*       |  na
| *individual*      |plan and sketch a potential final project (and put it on your personal website) |


## Photo of the week

![](../images/week01/photo-of-the-week.png)

**Fig.** First week of Fab Academy working from Poland. Lviv Crossaint. Wroclaw.


## MkDocs Website

I choose the MkDocs Template over using pure HTML as I have no experience with HTML. Moreover using template it will make easier to make the whole website coherent graphically.

After figuring out that I need a new MkDocs template for a personal website, rather than trying to modify the exiting HTML template in my folder (thanks to Rodrigo :)), I had to make it work on my local repository.



To get the mkdocs template working locally I had to:

1. Install mkdocs theme material, using the following commands (source:  [squidfunk](https://squidfunk.github.io/mkdocs-material/getting-started/))

  ```
  pip install mkdocs-material
  git clone https://github.com/squidfunk/mkdocs-material.git
  pip install -e mkdocs-material

  ```

2. Install the missing plugin, using the following command (source: [pypi](https://pypi.org/project/mkdocs-git-revision-date-localized-plugin/))


  ```
  pip install mkdocs-git-revision-date-localized-plugin

  ```


## Uploading to GIT repository
For individual repository:
In the Git Bash:
```
git add .
git commit -m "some string"
git push
```

For group repository:
```
git pull
git add .
git commit -m "some string"
git push
```
**git commit -m "..." - works, git commit -m '...' - doesn't work for me**
**Remember that you cannot push more than 10Mb at once.**
![](../images/meme01.png)

## Final Project Website and Personal

[About Me](https://fabacademy.org/2023/labs/ciudadmexico/students/judyta-cichocka/about/)

[Final Project](https://fabacademy.org/2023/labs/ciudadmexico/students/judyta-cichocka/projects/final-project/#week-01)

## Key take aways

- git push : local -> server
- git pull : server -> local
- question question marks


## Problems/Questions/Dilemas
1. Why does sometimes "commit" command runs, do not stop and not let me prograss in Git Bash?
2. Does pushing local repo with no docs deletes existing file in gitlab repo?
3. When I only modify files and not add or remove is the "git commit -m "..." command or I need to use the "git add ." and only then commit?
