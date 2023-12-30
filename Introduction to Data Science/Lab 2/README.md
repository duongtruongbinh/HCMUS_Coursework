# <font color=lightblue>Lab 02 - Introduction To Data Science/ CSC14119</font>

General information
- Affiliation: Department of Computer Science, Faculty of Information Technology, University of Science, Vietnam National University, Ho Chi Minh City
- *Laboratory instructor*: **Le Nhut Nam (Lê Nhựt Nam)**
- *LICENSE*
```
Lab 02 - Introduction To Data Science/ CSC14119 © 2023 by Department of Computer Science, Faculty of Information Technology, University of Science, Vietnam National University, Ho Chi Minh City is licensed under Attribution-NonCommercial-NoDerivatives 4.0 International
```

## <font color=lightblue>Laboratory instructions</font>

### <font color=lightblue>Set up your coding environment with Anaconda</font>

First, you should [download and install Anaconda](https://www.anaconda.com/download) for your operating systems. Then, starting install your development environment using ```requirements.txt```. 

**Note**: Suppose that you want to use Python 3.9, I built this requirement packages list base on Python 3.9. So if you want to install these packages in other Python version, please check all packages again via command ```conda search -c conda-forge -f  <package name>``` to verify the version of each package and change it in ```requirements.txt``` file. 

```bash
# create conda virtual environment
conda create --name min_ds-env python=3.9 -y

# activate created conda virtual environment
conda activate min_ds-env

# install dependencies
pip install -r requirements.txt
```

### <font color=lightblue>How to complete this assignment?</font>

You will do your assignment directly in this notebook. First, fill in your name and ID at the beginning of the file. In the notebook, fill in places that say:
```python
#TODO
```

During your work, you can print out the result, create more cells to test, or create more functions to handle things. Please note that <font color=red>you are not allowed to delete or modify my code cells</font> (except in the case that mentioned above). Let remove `raise NotImplementedError("not implement")` when running code.

Always press `Ctrl + S` in order to save your work.

**Notes:** 

    *  Copy means zero
    *  You have to submit your work on time. No exception
    *  Any questions about your grade are based on the assignment submitted on Moodle
    *  Wrong submission takes you -2 points

### <font color=lightblue>How to submit this assignment?</font>

When grading your assignment, I will choose `Kernel` - `Restart Kernel & Run All Cells` in order to restart the kernel and run all cells in your notebook. Therefore, you should do that before submitting to ensure that the outputs are all as expected.

After that, you make a submited direction as follow:

- Folder `StudentCode` (e.g. If your student code is 1234567, then your folder is `1234567`)

Finally, you compress your folder (`StudentCode`) and submit on Moodle. **The extension of the file is nothing else but `.zip`.**

<font color=red>Please strictly follow the submission rules.</font>

## <font color=lightblue>Laboratory structure explanation</font>

This lab project structure is built under the [Cookiecutter Data Science](https://github.com/drivendata/cookiecutter-data-science) - A logical, reasonably standardized, but flexible project structure for doing and sharing data science work. 

```
├── LICENSE-CC-BY-NC-ND-4.0.md
├── min_ds-env.yml
├── Makefile                 <- Makefile with commands like `make data` or `make train`
├── README.md                <- The top-level README for developers using this project.
├── data
│   ├── external             <- Data from third party sources.
│   ├── interim              <- Intermediate data that has been transformed.
│   ├── processed            <- The final, canonical data sets for modeling.
│   └── raw                  <- The original, immutable data dump.
│
│
├── models                   <- Trained and serialized models, model predictions, or model summaries
│
├── notebooks                <- Jupyter notebooks. Naming convention is a number (for ordering),
│                               the creator's initials, and a short `-` delimited description, e.g.
│                               `1.0-initial-data-exploration`.
│
├── references                <- Data dictionaries, manuals, and all other explanatory materials.
│
├── reports                   <- Generated analysis as HTML, PDF, LaTeX, etc. or your written by template such as https://github.com/Wandmalfarbe/pandoc-latex-template
│   └── figures               <- Generated graphics and figures to be used in reporting
│
├── requirements.txt          <- The requirements file for reproducing the analysis environment
│
├── src                       <- Source code for use in this project.
│   ├── __init__.py           <- Makes src a Python module
│   │
│   ├── data_module           <- Scripts to download or generate data
│   │   └── make_dataset.py
│   │
│   ├── features_module       <- Scripts to turn raw data into features for modeling
│   │   └── build_features.py
│   │
│   ├── models_module         <- Scripts to train models and then use trained models to make
│   │   │                        predictions
│   │   ├── predict_model.py
│   │   └── train_model.py
│   │
│   └── visualization_module  <- Scripts to create exploratory and results oriented visualizations
│       └── visualize.py
```

## <font color=lightblue>Contact information</font>

If you have any concerns with this assignment, please write an email and send it to class lecturer or laboratory instructor in order to get useful advices
- Class lecturer: **Le Ngoc Thanh** (lnthanh@fit.hcmus.edu.vn)
- Course laboratory instructor: **Le Nhut Nam** (lenam.fithcmus@gmail.com)

