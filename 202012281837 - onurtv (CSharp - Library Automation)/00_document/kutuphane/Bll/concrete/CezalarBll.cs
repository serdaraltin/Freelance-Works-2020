using Bll.Abstract;
using Dal.Abstract;
using entities.Concrete;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bll.concrete
{
    public class CezalarBll:ICezalarBll
    {
        ICezalarDal _Cezalar;
        public CezalarBll(ICezalarDal Cezalar)
        {
            _Cezalar = Cezalar;
        }
        public void Add(cezalar cezalar)
        {
            _Cezalar.Add(cezalar);
        }

        public void Delete(cezalar cezalar)
        {
            _Cezalar.Delete(cezalar);
        }

        public List<cezalar> getAll()
        {
            return _Cezalar.getAll();
        }

        public cezalar getOneById(int id)
        {
            return _Cezalar.getOne(x => x.id == id);
        }

        public void Update(cezalar cezalar)
        {
            _Cezalar.Update(cezalar);
        }
    }
}
