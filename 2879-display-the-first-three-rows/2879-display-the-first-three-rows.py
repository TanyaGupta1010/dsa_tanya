import pandas as pd

def selectFirstRows(students: pd.DataFrame) -> pd.DataFrame:
    return students.head(3)